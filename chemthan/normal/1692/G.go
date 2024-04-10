package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var in = bufio.NewReader(os.Stdin)

func readInt() int {
	nStr, _ := in.ReadString('\n')
	nStr = strings.ReplaceAll(nStr, "\r", "")
	nStr = strings.ReplaceAll(nStr, "\n", "")
	n, _ := strconv.Atoi(nStr)
	return n
}

func readLine() []string {
	line, _ := in.ReadString('\n')
	line = strings.ReplaceAll(line, "\r", "")
	line = strings.ReplaceAll(line, "\n", "")
	values := strings.Split(line, " ")
	return values
}

func readArrInt() []int {
	line := readLine()
	res := make([]int, 0, 0)
	for i := range line {
		var x, _ = strconv.Atoi(line[i])
		res = append(res, x)
	}
	return res
}

func main() {
	test := readInt()
	for ; 0 < test; test-- {
		ar := readArrInt()
		var n, k int
		n, k = ar[0], ar[1]
		a := readArrInt()
		b := make([]int, n, n)
		for i := 0; i+1 < n; i++ {
			if a[i+1]*2 <= a[i] {
				b[i+1] = 1
			}
			b[i+1] += b[i]
		}
		res := 0
		for i := 0; i+k < n; i++ {
			if b[i] == b[i+k] {
				res++
			}
		}
		fmt.Println(res)
	}
}