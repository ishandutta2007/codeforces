fun main(){
   var n = readLine()!!.toInt()
   var s = readLine()!!.toString()
   var ans = 0
   for (i in 0..n-3){
        if (s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x'){
            ans = ans + 1
        }
   }
   println(ans)
}