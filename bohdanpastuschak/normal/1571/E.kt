private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve(n: Int, s: String, a: String): Int {
    var ok = true
    for(i in 0 until n - 3){
        if (a[i] == '1'){
            if (i + 1 < n - 3 && a[i + 1] == '1'){
                ok = false
            }
            if (i + 3 < n - 3 && a[i + 3] == '1'){
                ok = false
            }
        }
    }

    if (!ok){
        return -1
    }

    var i = 0
    var ans = 0
    while(i < n - 3){
        if (a[i] == '0'){
            i++
            continue
        }

        if (i + 2 < n - 3 && a[i + 2] == '1'){

            var j = i + 2
            while (j + 2 < n - 3 && a[j + 2] == '1') j += 2
            //println("$i $j")
            for(k in i..j step 2){
                if (s[k] == ')') ans++
                if (s[k + 1] == '(') ans++
            }

            if (s[j + 2] == ')') ans++
            if (s[j + 3] == '(') ans++
            i = j + 1
        }else{
            if (s[i] == ')') ans++
            if (s[i + 1] == s[i + 2]) ans++
            if (s[i + 3] == '(') ans++
            i += 4
        }
    }

    return ans
}

fun main(){
    var t = readInt()
    while(t-- > 0){
        val n = readInt()
        val s = readLn()
        val a = readLn()
        println(solve(n, s, a))
    }
}