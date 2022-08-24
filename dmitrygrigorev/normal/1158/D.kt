import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

val reader = Scanner(System.`in`)

var pi = acos((-1).toDouble())

fun normalize(x : Double) : Double{
    var ans = x
    while (ans < 0){
        ans += 2*pi
    }
    while (ans >= 2*pi){
        ans -= 2*pi
    }
    return ans


}

fun main(){
    var n = reader.nextInt()
    var arr = Array<Pair<Int, Int>> (n) {i -> Pair(-1, -1)}
    for (i in 0 until n){
        var l = reader.nextInt()
        var r = reader.nextInt()
        arr[i] = Pair(l, r)
    }
    var s = reader.next()
    var pt = -1
    var mn = (2e9).toInt()
    for (i in 0 until n){
        if (arr[i].first < mn){
            mn = arr[i].first
            pt = i
        }
    }
    var used = Array<Boolean> (n) {i -> false}
    used[pt] = true
    var ans = Array<Int> (n) {i -> -1}
    ans[0] = pt
    for (i in 0 until n-2){
        var tet = mutableListOf<Pair<Double, Int>>()
        for (j in 0 until n){
            if (used[j]) continue
            var x = arr[j].first - arr[pt].first; var y = arr[j].second - arr[pt].second
            tet.add(Pair(atan2(y.toDouble(), x.toDouble()), j))
        }
        Collections.sort(tet, object: Comparator<Pair<Double, Int>>{
            override fun compare(p0: Pair<Double, Int>?, p1: Pair<Double, Int>?): Int {
                var D = normalize(p0!!.first - p1!!.first)
                if (D < pi) return -1
                if (D == pi) return 0
                return 1
            }
        })
        var win = -1
        if (s[i] == 'R'){
            win = tet[0].second
        }
        else win = tet.last().second
        ans[i+1] = win
        used[win] = true
        pt = win
    }
    for (i in 0 until n){
        if (!used[i]){
            ans[n-1] = i
        }
    }
    for (i in 0 until n){
        print(ans[i]+1)
        print(" ")
    }
}