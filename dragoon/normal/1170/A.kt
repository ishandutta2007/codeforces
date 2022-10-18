fun main() {
    var T = readLine()!!.toInt() // read integer from the input
    for (i in 1..T) {
var (A,B) = readLine()!!.trim().split("\\s+".toRegex()).map (String::toInt)
var C = 0
if (A < B) {C = A} else {C = B}
C = C - 1
A = A - C
B = B - C
    println("$C $A $B")
    }
}