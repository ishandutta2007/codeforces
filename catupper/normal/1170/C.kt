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
    for(i in 1..n){
        solve()
    }
}