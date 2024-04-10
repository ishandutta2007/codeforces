import java.util.*

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun ok(S: StringBuilder) : Boolean {
    // print(S)
    var bal = 0
    for (c in S) {
        if (c == '(') bal ++
        else bal --
        if (bal < 0) return false
    }
    return bal == 0
}

fun solve() : Boolean {
    val n = nextInt()
    val s = next()

    var i = s.length-1
    while (i >= 0 && s[i] != '(') i --
    if (i == -1) return false;
    var S = StringBuilder(s)
    S.deleteCharAt(i)
    S.insert(0,'(')
    if (ok(S)) return true

    i = 0
    while (i < s.length && s[i] != ')') i ++
    if (i == s.length) return false;
    S = StringBuilder(s)
    S.deleteCharAt(i)
    S.insert(S.length,')')
    if (ok(S)) return true

    return false
    // find the last '('
    // find the first ')' and move to end
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) {
        if (solve()) print("Yes")
        else print("No")
    }
}