

import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
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
            val solver = ADeadPixel()
            val testCount = Integer.parseInt(`in`.next())
            for (i in 1..testCount)
                solver.solve(i, `in`, out)
            out.close()
        }
    }

    internal class ADeadPixel {
        fun solve(testNumber: Int, `in`: FastInput, out: FastOutput) {
            val a = `in`.readInt()
            val b = `in`.readInt()
            val x = `in`.readInt()
            val y = `in`.readInt()

            val area = Math.max(Math.max(x, a - x - 1) * b, Math.max(y, b - y - 1) * a)
            out.println(area)
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

        fun println(c: Int): FastOutput {
            cache.append(c)
            println()
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
}