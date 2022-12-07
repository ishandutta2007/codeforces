fun main(args: Array<String>) {
    var s = readLine()!!.split(' ').map(String::toInt).toTypedArray()
    val n = s[0]
    var t = readLine()!!.split(' ').map(String::toInt).toTypedArray()
    val m = t[0]
    var a:Array<Int> = s.sliceArray(1..n)
    var b:Array<Int> = t.sliceArray(1..m)
    a.sort()
    b.sort()
    
    var c:Array<Int> = a.intersect(b.asIterable()).toTypedArray()
    a = a.subtract(c.asIterable()).toTypedArray()
    b = b.subtract(c.asIterable()).toTypedArray()
    print(a.size+b.size)
    print(' ')
    for(i in a){
        print(i)
        print(' ')
    }
    for(i in b){
        print(i)
        print(' ')
    }
}