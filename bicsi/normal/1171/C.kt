import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val t = readInt()
    for (tt in 1..t) {
        val s = readLn()
        val freq = IntArray(26)
        for (c in s.toCharArray()) {
            freq[(c - 'a').toInt()] += 1
        }

        var fst = 0
        var lst = 25
        while (freq[fst] == 0) ++fst
        while (freq[lst] == 0) --lst

        if (fst == lst) println(-1)
        else {
            freq[fst]--
            freq[lst]--

            val sb = StringBuilder()
            sb.append((fst + 'a'.toInt()).toChar())
            for (x in 0..25) {
                for (y in 1..freq[x])
                    sb.append((x + 'a'.toInt()).toChar())
            }
            sb.append((lst + 'a'.toInt()).toChar())
            println(sb.toString())
        }
    }
}