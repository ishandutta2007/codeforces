import kotlin.math.*
import kotlin.collections.*
import java.util.StringTokenizer
import java.io.PrintWriter

fun readLn() = readLine()!!

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    }
    return gcd(b, a%b)
}

var grid = Array<IntArray>(1000, {_ -> IntArray(1000)})
var xloc = IntArray(1000)
var yloc = IntArray(1000)

fun sgn(x: Int): Int {
    return (if (x==0) 0 else (if (x<0) -1 else 1))
}

var x = 0
var y = 0

fun main() {
    var arr = readLn().split(" ").map{it.toInt()}
    x = arr[0]
    y = arr[1]
    for (i in 1..666) {
        arr = readLn().split(" ").map{it.toInt()}
        xloc[i] = arr[0]
        yloc[i] = arr[1]
        grid[xloc[i]][yloc[i]] = i
    }
    while (x != 500 || y != 500) {
        var xnew = x
        var ynew = y
        if (x != 500) {
            xnew += sgn(500-x)
        }
        if (y != 500) {
            ynew += sgn(500-y)
        }
        if (grid[xnew][ynew] != 0) {
            xnew = x
        }
        println("$xnew $ynew")
        x = xnew
        y = ynew
        var (idx, xn, yn) = readLn().split(" ").map{it.toInt()}
        if (idx == -1) {
            return
        }
        grid[xloc[idx]][yloc[idx]] = 0
        grid[xn][yn] = idx
        xloc[idx] = xn
        yloc[idx] = yn
    }
    var xdir = 0
    var ydir = 0
    for (xd in -1..1 step 2) {
        for (yd in -1..1 step 2) {
            var cnt = 0
            for (a in 1..999) {
                for (b in 1..999) {
                    if (grid[a][b] != 0 && (sgn(a-500) == xd || sgn(b-500) == yd)) {
                        ++cnt
                    }
                }
            }
            //println("$xd $yd : $cnt")
            if (cnt >= 499) {
                xdir = xd
                ydir = yd
            }
        }
    }
    while (x < 999 && y < 999) {
        var xnew = x + xdir
        var ynew = y + ydir
        if (grid[xnew][ynew] != 0) {
            xnew = x
        }
        println("$xnew $ynew")
        x = xnew
        y = ynew
        var (idx, xn, yn) = readLn().split(" ").map{it.toInt()}
        if (idx == -1) {
            return
        }
        grid[xloc[idx]][yloc[idx]] = 0
        grid[xn][yn] = idx
        xloc[idx] = xn
        yloc[idx] = yn
    }
    throw IllegalArgumentException("Shouldn't reach end")
}