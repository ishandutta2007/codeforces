fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val b = readLine()!!.split(' ').map(String::toInt).sorted()

    var prefMax = IntArray(n + 1) { Int.MIN_VALUE}
    var suffMax = IntArray(n + 1) { Int.MIN_VALUE}

    for (i in 0 until n) {
        prefMax[i + 1] = Math.max(prefMax[i], b[i] - a[i])
    }

    for (i in n - 1 downTo 0) {
        suffMax[i] = Math.max(suffMax[i + 1], b[i + 1] - a[i])
    }

    val q = readLine()!!.toInt()
    val queries = readLine()!!.split(' ').map(String::toInt)

    for (x in queries) {
        var l = 0
        var r = n
        while (l < r) {
            val mid = (l + r) / 2
            if (a[mid] >= x) {
                r = mid
            } else {
                l = mid + 1
            }
        }
        var curAns = Math.max(prefMax[l], suffMax[l])
        curAns = Math.max(curAns, b[l] - x)
        print("$curAns ")
    }
}