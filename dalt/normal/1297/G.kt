
import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.util.stream.IntStream
import java.util.Arrays
import java.util.HashMap
import java.util.ArrayList
import java.io.OutputStreamWriter
import java.io.UncheckedIOException
import java.util.stream.Stream
import java.io.Closeable
import java.io.Writer
import java.util.function.ToIntFunction

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
            val solver = GMNumbers()
            solver.solve(1, `in`, out)
            out.close()
        }
    }

    internal class GMNumbers {
        var inf = 1e9.toInt() + 1

        fun solve(testNumber: Int, `in`: FastInput, out: FastOutput) {
            val m = `in`.readInt()
            var k = `in`.readInt()

            var mm = m
            for (i in 2..9) {
                while (mm % i == 0) {
                    mm /= i
                }
            }
            if (mm != 1) {
                out.println(-1)
                return
            }

            val factorList = ArrayList<Int>(10000)
            run {
                var i = 1
                while (i * i <= m) {
                    if (m % i != 0) {
                        i++
                        continue
                    }
                    factorList.add(i)
                    if (m / i != i) {
                        factorList.add(m / i)
                    }
                    i++
                }
            }
            val factors = factorList.stream().mapToInt(ToIntFunction<Int> { it.toInt() }).toArray()
            Arrays.sort(factors)
            val valToIndex = HashMap<Int, Int>(factors.size)
            for (i in factors.indices) {
                valToIndex[factors[i]] = i
            }
            val transfer = Array(factors.size) { IntArray(10) }
            for (i in factors.indices) {
                for (j in 0..9) {
                    transfer[i][j] = -1
                }
            }
            for (i in factors.indices) {
                for (j in 1..9) {
                    if (factors[i] % j == 0) {
                        transfer[i][j] = valToIndex[factors[i] / j]!!
                    }
                }
            }

            val dp = ArrayList<IntArray>(100000)
            val firstState = IntArray(factors.size)
            for (i in firstState.indices) {
                if (factors[i] < 10) {
                    firstState[i] = 1
                } else {
                    firstState[i] = 0
                }
            }
            dp.add(firstState)
            while (dp[dp.size - 1][factors.size - 1] < k) {
                k -= dp[dp.size - 1][factors.size - 1]
                val last = dp[dp.size - 1]
                val next = IntArray(factors.size)
                for (i in factors.indices) {
                    for (j in 1..9) {
                        if (transfer[i][j] != -1) {
                            next[i] = Math.min(next[i] + last[transfer[i][j]], inf)
                        }
                    }
                    next[i] = Math.min(next[i], inf)
                }
                dp.add(next)
            }

            var len = dp.size - 1
            var state = factors.size - 1
            while (len > 0) {
                val last = dp[len - 1]
                for (i in 1..9) {
                    if (transfer[state][i] != -1) {
                        if (last[transfer[state][i]] < k) {
                            k -= last[transfer[state][i]]
                        } else {
                            state = transfer[state][i]
                            len--
                            out.append(i)
                            break
                        }
                    }
                }
            }

            out.append(factors[state])
        }

    }

    internal class FastInput(private val `is`: InputStream) {
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
}