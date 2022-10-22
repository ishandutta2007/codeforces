private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun min(x: Int, y: Int):Int{
    if(x < y)return x
    else return y
}

fun solve(){
    var a = readLn()
    var b = readLn()
    var p = 0
    for(c in b){
        if(p >= a.length){
            println("NO")
            return
        }
        if(c == a[p]){
            p += 1
        }
        else if(c == '-'){
            println("NO")
            return
        }
        else if(p+1 < a.length && a[p] == '-' && a[p+1] == '-'){
            p += 2;            
        }
        else{
            println("NO")
            return
        }
    }
    if(p != a.length)println("NO")
    else println("YES")
}

fun main(){
    var n = readInt()
    var nums = readInts()
    var cnt = 0
    for(num in nums){
        if(num == -1)cnt += 1
    }
    var ans = Array(cnt, {i->mutableListOf<Int>()})
    var nxt = Array(cnt, {i->(i+1)%cnt})
    var p = cnt-1
    for(num in nums){
        var np = nxt[p]
        while(ans[np].isNotEmpty() && ans[np].last() == -1){
            np = nxt[np]
        }
        nxt[p] = np
        p = np
        ans[p].add(num)
    }
    println(cnt)
    for(i in 0..cnt-1){
        var k = ans[i].lastIndex
        print(k.toString() + " " + ans[i].dropLast(1).joinToString(" ") + "\n")
    }
}