import kotlin.collections.set
import java.util.*
import java.lang.String

fun main(args: Array<String>) {
    var data: MutableSet<Int> = mutableSetOf()
    for (i in 1..2) {
        var lst:MutableList<Int> = mutableListOf()
        
        for (elem in readLine()!!.split(' ')) {
            lst.add(elem.toInt())
        }
        
        lst.removeAt(0)
        for (elem in lst) {
            if (data.contains(elem))
                data.remove(elem)
            else
                data.add(elem)
        }
    }
    
    var s = "" + data.size
    for (elem in data) {
        s = s + " " + elem
    }
    println(s)
}