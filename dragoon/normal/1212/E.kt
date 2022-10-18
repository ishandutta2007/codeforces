import java.lang.Math.*
import java.util.*

/**
 * Created by Administrator on 9/2/2019.
 */

// for (i in 1..n) {}
// for (i in 5 downTo 1)
// for (i in 1..5 step 2)
// println(n)
// val freq = mutableMapOf<String, Int>()
// var places = mutableListOf<Place>()
// class Place(val x: Int, val b: Int)
// teams.sortWith(compareBy({it.size}));

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

class Team(val id: Int, val size: Int, val money: Int)

fun main(args: Array<String>) {
    val n = readInt()
    var teams = mutableListOf<Team>()
    for (i in 1..n) {
        val (size, money) = readInts()
        teams.add(Team(i, size, money))
    }
    teams.sortWith(compareBy({it.size}))
    var team_id = 0
    val num_table = readInt()
    var temp_tables = readInts()
    var tables = mutableListOf<Team>()
    for (i in 1..num_table) {
        tables.add(Team(i, temp_tables[i - 1], 0))
    }
    tables.sortWith(compareBy({it.size}))
    val pq = PriorityQueue<Team>(Comparator<Team>{a1, a2 -> a2.money - a1.money})
    var ans = 0
    val ansList = mutableListOf<Team>()
    for (t in tables) {
        while (team_id < n && teams[team_id].size <= t.size) {
            pq.add(teams[team_id])
            team_id++
        }
        if (pq.isNotEmpty()) {
            val x = pq.poll()
            ansList.add(Team(0, x.id, t.id))
            ans += x.money
        }
    }
    println("${ansList.size} $ans")
    for (i in ansList) println("${i.size} ${i.money}")
}