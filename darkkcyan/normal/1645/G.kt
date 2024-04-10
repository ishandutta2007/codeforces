fun main() {
    val k = readLine()!!.toInt()
    val s = readLine()!!
    val t = readLine()!!
    var sum = IntArray(k)
    
    var carry = 0
    for (i in k - 1 downTo 0) {
        val u = s[i].toInt() - 'a'.toInt()
        val v = t[i].toInt() - 'a'.toInt()
        carry = carry + u + v
        sum[i] = carry % 26
        carry /= 26
    }
    println(sequence {
        for (i in 0 until k) {
            carry = carry * 26 + sum[i]
            yield((carry / 2 + 'a'.toInt()).toChar())
            carry %= 2
        }
    }.joinToString("")) 
}