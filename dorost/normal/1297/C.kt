fun main(){
   var t = readLine()!!.toInt()
   for (i in 1..t){
        var n = readLine()!!.toInt()
        val s: ArrayList<String> = ArrayList()
        val a = readLine()!!.split(' ').map{it.toInt()}
        var ans = 0
        var max = -100000
        var an  = -1
        var min = 100000
        var an1 = -1
        for (i in 1..n){
            s.add("0")
        }
        for (i in 0..n-1){
            if (a[i] >= 0){
                ans += a[i]
                s[i] = "1"
                if (a[i] < min && a[i] != 0){
                    min = a[i]
                    an1 = i
                }
            }else{
                if (a[i] > max){
                    max = a[i]
                    an = i
                }
            }
        }
        if (min < (max * -1) && an1 != -1 && min != 100000){
            ans -= min
            s[an1] = "0"
        }else if (an != -1 && max != -100000){
            ans += max
            s[an] = "1"
        }
        println(ans)
        for (i in 0..n-1){
            print(s[i])
        }
        println()
   }
}