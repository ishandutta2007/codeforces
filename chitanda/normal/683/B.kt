fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var s = Array(n, {i->object{var name:String = ""; var h:Int = 0}})
    for(i in 0..n-1){
        var t = readLine()!!.split(' ')
        s[i].name = t[0]
        s[i].h = t[1].toInt()
    }
    s.sortBy{it.h}
    for(i in s) println(i.name)
}