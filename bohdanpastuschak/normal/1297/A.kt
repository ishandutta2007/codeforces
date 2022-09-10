private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while(t-- > 0)
    {
        var n = readInt()
        if (n < 1000){
            println(n)
            continue
        }

        if (n < 999500){
            var x = (n + 500) / 1000
            print(x)
            println("K")
            continue;
        }

        var x = (n + 500000) / 1000000
        print(x)
        println("M")
        continue;

    }
}