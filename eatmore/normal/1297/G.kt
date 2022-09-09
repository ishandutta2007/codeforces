import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object G {
    fun c(cPrev: Int, n: Int, k: Int): Int {
        var k = k
        var cur = cPrev.toLong()
        if (2 * k > n) {
            k = n - k
        }
        for (i in 0 until k) {
            cur = cur * (n - i) / (i + 1)
            if (cur > Int.MAX_VALUE) {
                cur = Int.MAX_VALUE.toLong()
            }
        }
        return cur.toInt()
    }

    fun multiC(len: Int, c1: Int, c2: Int, c3: Int, c4: Int, c5: Int, c6: Int, c7: Int, c8: Int, c9: Int): Int {
        var len = len
        var res = 1
        res = c(res, len, c1)
        len -= c1
        res = c(res, len, c2)
        len -= c2
        res = c(res, len, c3)
        len -= c3
        res = c(res, len, c4)
        len -= c4
        res = c(res, len, c5)
        len -= c5
        res = c(res, len, c6)
        len -= c6
        res = c(res, len, c7)
        len -= c7
        res = c(res, len, c8)
        len -= c8
        res = c(res, len, c9)
        len -= c9
        if (len != 0) {
            throw AssertionError()
        }
        return res
    }

    @Throws(Exception::class)
    fun solve() {
        var m = scanInt()
        var k = scanInt() - 1
        var c2 = 0
        var c3 = 0
        var c5 = 0
        var c7 = 0
        while (m % 2 == 0) {
            ++c2
            m /= 2
        }
        while (m % 3 == 0) {
            ++c3
            m /= 3
        }
        while (m % 5 == 0) {
            ++c5
            m /= 5
        }
        while (m % 7 == 0) {
            ++c7
            m /= 7
        }
        if (m != 1) {
            out!!.print(-1)
            return
        }
        var len: Int
        len = 1
        len@ while (true) {
            var ck = k
            var c4 = 0
            var c2_1 = c2
            while (c2_1 >= 0) {
                var c8 = 0
                var c2_2 = c2_1
                while (c2_2 >= 0) {
                    var c6 = 0
                    var c2_3 = c2_2
                    var c3_1 = c3
                    while (c2_3 >= 0 && c3_1 >= 0) {
                        var c9 = 0
                        var c3_2 = c3_1
                        while (c3_2 >= 0) {
                            val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                            if (c1 >= 0) {
                                val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                if (c > ck) {
                                    break@len
                                }
                                ck -= c
                            }
                            ++c9
                            c3_2 -= 2
                        }
                        ++c6
                        --c2_3
                        --c3_1
                    }
                    ++c8
                    c2_2 -= 3
                }
                ++c4
                c2_1 -= 2
            }
            k = ck
            len++
        }
        val l = len
        i@ for (i in 0 until l) {
            var ck: Int
            --len
            ck = k
            var c4 = 0
            var c2_1 = c2
            while (c2_1 >= 0) {
                var c8 = 0
                var c2_2 = c2_1
                while (c2_2 >= 0) {
                    var c6 = 0
                    var c2_3 = c2_2
                    var c3_1 = c3
                    while (c2_3 >= 0 && c3_1 >= 0) {
                        var c9 = 0
                        var c3_2 = c3_1
                        while (c3_2 >= 0) {
                            val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                            if (c1 >= 0) {
                                val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                if (c > ck) {
                                    out!!.print('1')
                                    continue@i
                                }
                                ck -= c
                            }
                            ++c9
                            c3_2 -= 2
                        }
                        ++c6
                        --c2_3
                        --c3_1
                    }
                    ++c8
                    c2_2 -= 3
                }
                ++c4
                c2_1 -= 2
            }
            k = ck
            if (c2 >= 1) {
                --c2
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('2')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                ++c2
            }
            if (c3 >= 1) {
                --c3
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('3')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                ++c3
            }
            if (c2 >= 2) {
                c2 -= 2
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('4')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                c2 += 2
            }
            if (c5 >= 1) {
                --c5
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('5')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                ++c5
            }
            if (c2 >= 1 && c3 >= 1) {
                --c2
                --c3
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('6')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                ++c2
                ++c3
            }
            if (c7 >= 1) {
                --c7
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('7')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                ++c7
            }
            if (c2 >= 3) {
                c2 -= 3
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('8')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                c2 += 3
            }
            if (c3 >= 2) {
                c3 -= 2
                ck = k
                var c4 = 0
                var c2_1 = c2
                while (c2_1 >= 0) {
                    var c8 = 0
                    var c2_2 = c2_1
                    while (c2_2 >= 0) {
                        var c6 = 0
                        var c2_3 = c2_2
                        var c3_1 = c3
                        while (c2_3 >= 0 && c3_1 >= 0) {
                            var c9 = 0
                            var c3_2 = c3_1
                            while (c3_2 >= 0) {
                                val c1 = len - c2_3 - c3_2 - c4 - c5 - c6 - c7 - c8 - c9
                                if (c1 >= 0) {
                                    val c = multiC(len, c1, c2_3, c3_2, c4, c5, c6, c7, c8, c9)
                                    if (c > ck) {
                                        out!!.print('9')
                                        continue@i
                                    }
                                    ck -= c
                                }
                                ++c9
                                c3_2 -= 2
                            }
                            ++c6
                            --c2_3
                            --c3_1
                        }
                        ++c8
                        c2_2 -= 3
                    }
                    ++c4
                    c2_1 -= 2
                }
                k = ck
                c3 += 2
            }
            throw AssertionError()
        }
    }

    @Throws(IOException::class)
    fun scanInt(): Int {
        return scanString().toInt()
    }

    @Throws(IOException::class)
    fun scanLong(): Long {
        return scanString().toLong()
    }

    @Throws(IOException::class)
    fun scanString(): String {
        while (tok == null || !tok!!.hasMoreTokens()) {
            tok = StringTokenizer(`in`!!.readLine())
        }
        return tok!!.nextToken()
    }

    var `in`: BufferedReader? = null
    var out: PrintWriter? = null
    var tok: StringTokenizer? = null
    fun main() {
        try {
            `in` = BufferedReader(InputStreamReader(System.`in`))
            out = PrintWriter(System.out)
            solve()
            `in`!!.close()
            out!!.close()
        } catch (e: Throwable) {
            e.printStackTrace()
            System.exit(1)
        }
    }
}

fun main() {
    G.main()
}