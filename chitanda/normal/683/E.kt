fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var use = Array<Int>(n, {i->0})
    for(i in 0..n - 1){
        var now:Int = 0
        for(j in 0..n-1)
            if(use[j] == 0){
                now++
                if(now == a[i] + 1){
                    use[j] = i + 1
                    break
                }
            }
    }
    for(i in 0..n - 1){
        print(use[i])
        print(' ')    
    }
}