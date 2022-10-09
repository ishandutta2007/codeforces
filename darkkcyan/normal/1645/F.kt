fun main() {
    readLine()!!
    val a = readLine()!!.split(' ').map{it.toInt()}.sorted()
    val maxval = 150000 + 2
    val has = BooleanArray(maxval)
    var ans = 0
    for (i in a) {
        for (delta in listOf(-1, 0, 1)) {
            if (i + delta <= 0) continue
            if (has[i + delta]) {
                continue
            }
            has[i + delta] = true
            ans ++
            break
        }
    }
    println(ans)
}