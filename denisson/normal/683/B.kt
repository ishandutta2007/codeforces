fun main(args: Array<String>) { 
    var sn = readLine()!!
    var n : Int = sn.toInt()
    var mas = Array(5007, { i -> "" })
    var mas2 = Array(5007, { i -> 0 })
    for (i in 1..n){
        var (s, a) = readLine()!!.split(' ')
        var d = a.toInt()
        mas[i] = s
        mas2[i] = d
    }
    for (asdfasdf in 1..n){
        for (i in 1..n-1){
            if (mas2[i] > mas2[i + 1]){
                var q = mas2[i]
                mas2[i] = mas2[i + 1]
                mas2[i + 1] = q
                var t = mas[i]
                mas[i] = mas[i + 1]
                mas[i + 1] = t
            }
        }
    }
    for (i in 1..n){
        println(mas[i])
    }
}