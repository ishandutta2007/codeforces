

import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.util.Arrays
import java.io.UncheckedIOException
import java.io.Closeable
import java.io.Writer
import java.io.OutputStreamWriter

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
object programkt {
    @Throws(Exception::class)
    @JvmStatic
    fun main(args: Array<String>) {
        val thread = Thread(null, TaskAdapter(), "", (1 shl 27).toLong())
        thread.start()
        thread.join()
    }

    internal class TaskAdapter : Runnable {
        override fun run() {
            val inputStream = System.`in`
            val outputStream = System.out
            val `in` = FastInput(inputStream)
            val out = FastOutput(outputStream)
            val solver = DBonusDistribution()
            val testCount = Integer.parseInt(`in`.next())
            for (i in 1..testCount)
                solver.solve(i, `in`, out)
            out.close()
        }
    }

    internal class DBonusDistribution {
        fun solve(testNumber: Int, `in`: FastInput, out: FastOutput) {
            val n = `in`.readInt()
            var k = `in`.readInt()
            val a = arrayOfNulls<Employee>(n)
            for (i in 0 until n) {
                a[i] = Employee()
                a[i]?.v = `in`.readInt()
            }
            val sorted = a.clone()
            Arrays.sort(sorted) { x, y -> -Integer.compare(x!!.v, y!!.v) }
            for (i in 1 until n) {
                var allow = sorted[i - 1]!!.v - 1 - sorted[i]!!.v
                allow = Math.min(k, allow)
                k -= allow
                sorted[i]!!.v += allow
                sorted[i]!!.k = allow
            }
            val avg = k / n
            for (i in 0 until n) {
                sorted[i]!!.k += avg
            }
            val remain = k % n
            for (i in 0 until remain) {
                sorted[i]!!.k++
            }

            for (e in a) {
                out.append(e!!.k).append(' ')
            }
            out.println()
        }

    }

    internal class FastOutput(private val os: Writer) : AutoCloseable, Closeable, Appendable {
        private val cache = StringBuilder(10 shl 20)

        override fun append(csq: CharSequence): FastOutput {
            cache.append(csq)
            return this
        }

        override fun append(csq: CharSequence, start: Int, end: Int): FastOutput {
            cache.append(csq, start, end)
            return this
        }

        constructor(os: OutputStream) : this(OutputStreamWriter(os)) {}

        override fun append(c: Char): FastOutput {
            cache.append(c)
            return this
        }

        fun append(c: Int): FastOutput {
            cache.append(c)
            return this
        }

        fun println(): FastOutput {
            cache.append(System.lineSeparator())
            return this
        }

        fun flush(): FastOutput {
            try {
                os.append(cache)
                os.flush()
                cache.setLength(0)
            } catch (e: IOException) {
                throw UncheckedIOException(e)
            }

            return this
        }

        override fun close() {
            flush()
            try {
                os.close()
            } catch (e: IOException) {
                throw UncheckedIOException(e)
            }

        }

        override fun toString(): String {
            return cache.toString()
        }

    }

    internal class FastInput(private val `is`: InputStream) {
        private val defaultStringBuf = StringBuilder(1 shl 13)
        private val buf = ByteArray(1 shl 20)
        private var bufLen: Int = 0
        private var bufOffset: Int = 0
        private var next: Int = 0

        private fun read(): Int {
            while (bufLen == bufOffset) {
                bufOffset = 0
                try {
                    bufLen = `is`.read(buf)
                } catch (e: IOException) {
                    bufLen = -1
                }

                if (bufLen == -1) {
                    return -1
                }
            }
            return buf[bufOffset++].toInt()
        }

        fun skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read()
            }
        }

        operator fun next(): String {
            return readString()
        }

        fun readInt(): Int {
            var sign = 1

            skipBlank()
            if (next == '+'.toInt() || next == '-'.toInt()) {
                sign = if (next == '+'.toInt()) 1 else -1
                next = read()
            }

            var `val` = 0
            if (sign == 1) {
                while (next >= '0'.toInt() && next <= '9'.toInt()) {
                    `val` = `val` * 10 + next - '0'.toInt()
                    next = read()
                }
            } else {
                while (next >= '0'.toInt() && next <= '9'.toInt()) {
                    `val` = `val` * 10 - next + '0'.toInt()
                    next = read()
                }
            }

            return `val`
        }

        fun readString(builder: StringBuilder): String {
            skipBlank()

            while (next > 32) {
                builder.append(next.toChar())
                next = read()
            }

            return builder.toString()
        }

        fun readString(): String {
            defaultStringBuf.setLength(0)
            return readString(defaultStringBuf)
        }

    }

    internal class Employee {
        var v: Int = 0
        var k: Int = 0

    }
}