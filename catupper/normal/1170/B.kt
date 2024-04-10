private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun min(x: Int, y: Int):Int{
    if(x < y)return x
    else return y
}

fun solve(){
    var (ab,ac) = readInts()
    var a = min(ab-1, ac-1)
    var b = ab-a
    var c = ac-a
    print(a)
    print(" ")
    print(b)
    print(" ")
    println(c)
}

fun main(){
    var n = readInt()
    var nums = readInts()
    var mx = -1
    var smx = -1
    var ans = 0
    for(num in nums){
        if(num < smx){
            ans += 1
            continue
        }
        if(smx < num){
            smx = num
        }
        if(smx > mx){
            val k = smx
            smx = mx
            mx = k
        }
    }
    println(ans)
}