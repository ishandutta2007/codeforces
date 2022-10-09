fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}.sorted()
    val x = MutableList<Int>(0) {0}
    val y = MutableList<Int>(0) {0}
    for (i in a) {
        if (x.size == 0 || x.last() != i) {
            x.add(i)
        } else if (y.size == 0 || y.last() != i) {
            y.add(i)
        } else {
            println("NO")
            System.exit(0)
        }
    }
    println("YES")
    println(x.size)
    println(x.joinToString(" "))
    println(y.size)
    println(y.reversed().joinToString(" "))
}