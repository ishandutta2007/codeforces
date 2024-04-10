import java.util.ArrayList
import java.util.Collections
import java.util.Comparator
import java.util.HashMap
import java.util.HashSet
import java.util.Scanner
fun main(args:Array<String>) {
    var `in` = Scanner(System.`in`)
    var n = `in`.nextInt()
    var v = ArrayList<Int>()
    var d = ArrayList<Int>()
    for (i in 0 until n){
        var t = `in`.nextInt() 
        v.add(t)
        d.add(t)
    }
    Collections.sort<Int>(v)
    var prev= 0
    var sol = ArrayList<Int>()
    for (i in 0 until n){
        if(v.get(i) != prev){
            sol.add(v.get(i))
        }
        prev = v.get(i)
    }
    if (sol.size < 3) {
        println("-1 -1 -1")
    }
    else {
        for(i in 0 until 3) {
            var ind = -1;
            for(j in 0 until d.size) {
                if(d.get(j)==sol.get(i)){
                    ind = j
                }
            }
            print(ind+1)
            print(" ")
        }
    }
}