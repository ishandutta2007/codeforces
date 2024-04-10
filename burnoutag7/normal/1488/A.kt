//t-shirt please t-shirt!

import java.util.*

fun solve(){
    var (x,y)=readLine()!!.split(' ').map{it.toInt()}
    var ans:Int=0
    while(y>=x){
        var c:Int=x
        while(c.toLong()*10<=y)c*=10
        ans+=y/c
        y%=c
    }
    println(ans+y)
}

fun main(){
    var T:Int=Integer.valueOf(readLine())
    while(T>0){
        solve()
        T--
    }
}