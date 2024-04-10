fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }

fun fin() {
    print("NO"); System.exit(0)
}

fun main(args: Array<String>) {
    var (x,y,z) = nextInts()
    var (a,b,c) = nextInts()
    a -= x; if (a < 0) fin()
    var sum = a+b-y; if (sum < 0) fin()
    sum += c-z; if (sum < 0) fin()
    print("YES")
}