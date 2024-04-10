fun main() {
    var (n, k) = readLine()!!.split(' ').map {it.toInt()}
    val maxbit = 32
    val p2 = IntArray(maxbit) 
    for (i in 0 until maxbit) {
        if (((n shr i) and 1) == 1) {
            p2[i] ++
            k -= 1
        }
    }
    if (k < 0) {
        println("NO")
        System.exit(0)
    }
    for (i in maxbit - 1 downTo 1) {
        while (k > 0 && p2[i] > 0) {
            p2[i] --
            p2[i - 1] += 2
            k --
        }
    }
    if (k > 0) {
        println("NO")
        System.exit(0)
    }
    println("YES")
    println(p2.withIndex().flatMap { (id, v) -> List(v) {1 shl id} }.joinToString(" "))
}