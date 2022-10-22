fun main(){
   var n = readLine()!!.toInt()
   val b = readLine()!!.split(' ').map {it.toInt()}
   val a = b.reversed()
   var ans = 0
   val x = mutableListOf<Int>()
   for (i in 0..(n - 1)){
    var f = 1
    var d = i - 1
        for (j in 0..d){
            if (a[i] == a[j]){
                f = 0
            }
        }
        if (f == 1){
            ans = ans + 1
            x.add(a[i])
        }
   }
   println(ans)
   for (i in 0..ans-1) {
        print(x[ans - 1 - i])
        print(' ')
   }
}