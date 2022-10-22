fun main(){
   var t = readLine()!!.toInt()
   for (i in 1..t){
        var n = readLine()!!.toInt()
        val x: ArrayList<Int> = ArrayList()
        val y: ArrayList<Int> = ArrayList()
        for (i in 1..n){
            val (a, b) = readLine()!!.split(' ').map {it.toInt()}
            x.add(a)
            x.add(b)
            y.add(a)
            y.add(b)
            y.add(a + 1)
            y.add(b + 1)
            y.add(a - 1)
            y.add(b - 1)
        }
        var ans = -1
        for (i in 0..n*6-1){
            var d = 0
            for (j in 0..n-1){
                if (y[i] >= x[j * 2] && y[i] <= x[j * 2 + 1]){
                    d += 1
                }
            }
            if(d == 1){
                ans = y[i]
            }
        }
        println(ans)
   }
}