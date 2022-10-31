private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

class Segment(val index: Int, val lo: Int, val hi: Int)
class Event(val x: Int, val delta: Int)

fun compareEvents(a: Event, b: Event): Int {
    if (a.x != b.x) return a.x.compareTo(b.x)
    return -a.delta.compareTo(b.delta)
}

fun main(args: Array<String>) {
    val t = readInt()
    repeat(t) {
        val segments = ArrayList<Segment>()
        val events = ArrayList<Event>()
        val n = readInt()
        for (i in 0..n-1) {
            val (lo, hi) = readInts()
            segments.add(Segment(i, lo, hi))
            events.add(Event(lo, 1))
            events.add(Event(hi, -1))
        }
        events.sortWith(Comparator(::compareEvents))
        var nest = 0
        var threshold: Int? = null
        for ((index, event) in events.withIndex()) {
            nest += event.delta
            if (nest == 0 && index != events.size - 1) {
                threshold = event.x
            }
        }
        if (threshold == null) {
            println("-1")
        } else {
            println(segments.map { if (it.hi <= threshold) 1 else 2 }.joinToString(" "))
        }
    }
}