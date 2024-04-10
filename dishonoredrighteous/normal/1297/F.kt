import java.util.*
import kotlin.collections.ArrayList

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }

fun solve() {
    var (n, m) = readInts()

    var a = ArrayList<Pair<Int, Int>>()

    var events = ArrayList<Triple<Int, Int, Int>>()
    for (i in 0 until n) {
        var (l, r) = readInts()
        events.add(Triple(l, 1, i))
        events.add(Triple(r, -1, i))
        a.add(Pair(l, r))
    }

    var sortedEvents = events.sortedWith(compareBy({it.first}, {-it.second}, {it.third}))
    var nxt = 0
    var curDay = 1
    var curRest = m

    var bad = TreeSet<Pair<Int, Int>>(compareBy({it.first}, {it.second}))
    var opened = TreeSet<Pair<Int, Int>>(compareBy({it.first}, {it.second}))

    var ans = ArrayList<Int>()
    for (i in 0 until n) {
        ans.add(0)
    }

    var res = 0
    while (true) {
        while (nxt < sortedEvents.size && sortedEvents[nxt].first == curDay && sortedEvents[nxt].second == 1) {
            opened.add(Pair(a[sortedEvents[nxt].third].second, sortedEvents[nxt].third))
            nxt += 1
        }

        while (!bad.isEmpty() && curRest > 0) {
            var cur = bad.first()
            bad.remove(cur)

            ans[cur.second] = curDay
            curRest -= 1

            if (curDay - cur.first > res) {
                res = curDay - cur.first
            }
        }

        while (!opened.isEmpty() && curRest > 0) {
            var cur = opened.first()
            opened.remove(cur)

            ans[cur.second] = curDay
            curRest -= 1
        }

        while (nxt < sortedEvents.size && sortedEvents[nxt].first == curDay && sortedEvents[nxt].second == -1) {
            if (opened.contains(Pair(sortedEvents[nxt].first, sortedEvents[nxt].third))) {
                opened.remove(Pair(sortedEvents[nxt].first, sortedEvents[nxt].third))
                bad.add(Pair(sortedEvents[nxt].first, sortedEvents[nxt].third))
            }
            nxt += 1
        }

        if (bad.isEmpty() && opened.isEmpty() && nxt == sortedEvents.size) {
            break
        }

        if (bad.isEmpty() && opened.isEmpty()) {
            curDay = sortedEvents[nxt].first
            curRest = m
        } else {
            curDay += 1
            curRest = m
        }
    }

    println(res)
    for (i in ans) {
        print(i)
        print(' ')
    }
    println()
}

fun main(args: Array<String>) {
    var t = readInt()

    while (t > 0) {
        t -= 1
        solve()
    }
}