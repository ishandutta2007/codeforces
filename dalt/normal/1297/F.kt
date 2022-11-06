import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.util.Arrays
import java.io.UncheckedIOException
import java.util.TreeMap
import java.io.Closeable
import java.io.Writer
import kotlin.collections.Map.Entry
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
            val solver = FMovieFan()
            val testCount = Integer.parseInt(`in`.next())
            for (i in 1..testCount)
                solver.solve(i, `in`, out)
            out.close()
        }
    }

    internal class FMovieFan {
        var m: Long = 0

        fun solve(testNumber: Int, `in`: FastInput, out: FastOutput) {
            val n = `in`.readInt()
            m = `in`.readInt().toLong()
            val movies = arrayOfNulls<Movie>(n)
            for (i in 0 until n) {
                val a = `in`.readInt()
                val b = `in`.readInt()
                movies[i] = Movie()
                movies[i]!!.l = dayBegin(a)
                movies[i]!!.r = dayEnd(b)
            }
            val sorted = movies.clone()
            Arrays.sort(sorted) { a, b -> java.lang.Long.compare(a!!.r, b!!.r) }
            val map = IntervalBooleanMap()
            var day: Long = 0
            for (movie in sorted) {
                val index = map.firstFalse(movie!!.l)
                movie!!.day = index
                map.setTrue(index, index)
                if (movie!!.day > movie!!.r) {
                    day = Math.max(DigitUtils.ceilDiv(movie!!.day - movie!!.r, m), day)
                }
            }
            out.println(day)
            for (i in 0 until n) {
                out.append(movies[i]!!.day / m).append(' ')
            }
            out.println()
        }

        fun dayBegin(i: Int): Long {
            return i * m
        }

        fun dayEnd(i: Int): Long {
            return dayBegin(i + 1) - 1
        }

    }

    internal class IntervalBooleanMap : Iterable<IntervalBooleanMap.Interval> {
        private val map = TreeMap<Long, IntervalBooleanMap.Interval>()
        private var total: Long = 0

        fun removeInterval(interval: IntervalBooleanMap.Interval) {
            map.remove(interval.l)
            total -= interval.length()
        }

        fun addInterval(interval: IntervalBooleanMap.Interval) {
            if (interval.length() <= 0) {
                return
            }
            map.put(interval.l, interval)
            total += interval.length()
        }

        fun firstFalse(l: Long): Long {
            val entry = map.floorEntry(l)
            if (entry == null || entry.value.r < l) {
                return l
            }
            val last = entry.value
            while (true) {
                val ceil = map.ceilingEntry(last.r + 1)
                if (ceil == null || ceil.value.l > last.r + 1) {
                    break
                }
                last.r = ceil.value.r
                map.remove(ceil.key)
            }
            return entry.value.r + 1
        }

        fun setTrue(l: Long, r: Long) {
            if (l > r) {
                return
            }
            val interval = IntervalBooleanMap.Interval()
            interval.l = l
            interval.r = r
            while (true) {
                val floorEntry = map.floorEntry(interval.l) ?: break
                val floorInterval = floorEntry.value
                if (floorInterval.r >= interval.r) {
                    return
                } else if (floorInterval.r < interval.l) {
                    break
                } else {
                    interval.l = Math.min(interval.l, floorInterval.l)
                    removeInterval(floorInterval)
                }
            }
            while (true) {
                val ceilEntry = map.ceilingEntry(interval.l) ?: break
                val ceilInterval = ceilEntry.value
                if (ceilInterval.l <= interval.l) {
                    return
                } else if (ceilInterval.l > interval.r) {
                    break
                } else {
                    interval.r = Math.max(interval.r, ceilInterval.r)
                    removeInterval(ceilInterval)
                }
            }

            addInterval(interval)
        }

        override fun iterator(): Iterator<IntervalBooleanMap.Interval> {
            return map.values.iterator()
        }

        override fun toString(): String {
            val builder = StringBuilder()
            for (interval in map.values) {
                builder.append(interval).append(',')
            }
            if (builder.length > 0) {
                builder.setLength(builder.length - 1)
            }
            return builder.toString()
        }

        class Interval {
            internal var l: Long = 0
            internal var r: Long = 0

            internal fun length(): Long {
                return r - l + 1
            }

            override fun toString(): String {
                return String.format("[%d, %d]", l, r)
            }

        }

    }

    internal class Movie {
        var l: Long = 0
        var r: Long = 0
        var day: Long = 0

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

        fun append(c: Long): FastOutput {
            cache.append(c)
            return this
        }

        fun println(c: Long): FastOutput {
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

    internal object DigitUtils {

        fun floorDiv(a: Long, b: Long): Long {
            return if (a < 0) -ceilDiv(-a, b) else a / b
        }

        fun ceilDiv(a: Long, b: Long): Long {
            if (a < 0) {
                return -floorDiv(-a, b)
            }
            val c = a / b
            return if (c * b < a) {
                c + 1
            } else c
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