
import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.util.ArrayList
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
            val solver = EModernizationOfTreeland()
            val testCount = Integer.parseInt(`in`.next())
            for (i in 1..testCount)
                solver.solve(i, `in`, out)
            out.close()
        }
    }

    internal class EModernizationOfTreeland {
        var k: Int = 0
        var now: Int = 0
        var g: Array<MutableList<UndirectedEdge>?>? = null;
        var add: BooleanArray? = null;

        fun solve(testNumber: Int, `in`: FastInput, out: FastOutput) {
            val n = `in`.readInt()
            k = `in`.readInt()
            g = Graph.createUndirectedGraph(n)
            for (i in 1 until n) {
                val a = `in`.readInt() - 1
                val b = `in`.readInt() - 1
                Graph.addUndirectedEdge(g!!, a, b)
            }
            if (k == 1) {
                out.println("Yes")
                out.println(1)
                out.println(1)
                return
            }
            if (k > n) {
                out.println("No")
                return
            }
            if (k == 2) {
                out.println("Yes")
                out.println(2)
                out.append(1).append(' ').append(g!![0]!![0]!!.to + 1).println()
                return
            }

            var root = -1
            for (i in 0 until n) {
                if (g!![i]!!.size == 1) {
                    continue
                }
                root = i
                break
            }

            if (root == -1) {
                out.println("No")
                return
            }

            add = BooleanArray(n)
            add!![root] = true
            now = 1
            dfs(root, -1)
            if (now != k) {
                out.println("No")
                return
            }
            out.println("Yes")
            var cnt = 0
            for (x in add!!) {
                if (x) {
                    cnt++
                }
            }
            out.println(cnt)
            for (i in 0 until n) {
                if (add!![i]) {
                    out.append(i + 1).append(' ')
                }
            }
            out.println()
        }

        fun dfs(root: Int, p: Int) {
            if (now == k) {
                return
            }
            if (g!![root]!!.size == 1) {
                return
            }
            now--
            for (e in g!![root]!!) {
                if (e.to == p) {
                    continue
                }
                add!![e.to] = true
                now++
                if (now == k) {
                    break
                }
            }

            for (e in g!![root]!!) {
                if (e.to == p) {
                    continue
                }
                if (add!![e.to]) {
                    dfs(e.to, root)
                }
            }
        }

    }

    internal class UndirectedEdge(to: Int) : DirectedEdge(to) {
        var rev: UndirectedEdge? = null

    }

    internal open class DirectedEdge(var to: Int) {

        override fun toString(): String {
            return "->$to"
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

    internal object Graph {
        fun addUndirectedEdge(g: Array<MutableList<UndirectedEdge>?>, s: Int, t: Int) {
            val toT = UndirectedEdge(t)
            val toS = UndirectedEdge(s)
            toT.rev = toS
            toS.rev = toT
            g[s]!!.add(toT)
            g[t]!!.add(toS)
        }

        fun createUndirectedGraph(n: Int): Array<MutableList<UndirectedEdge>?> {
            val ans = arrayOfNulls<MutableList<UndirectedEdge>?>(n)
            for (i in 0 until n) {
                ans[i] = ArrayList<UndirectedEdge>()
            }
            return ans
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

        fun println(c: String): FastOutput {
            cache.append(c)
            println()
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