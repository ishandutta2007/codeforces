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
		var n = readInt()
		var a = readArrInt()
		var hs map[int]int
		hs = make(map[int]int)
		for i := range a {
			hs[a[i]]++
		}
		res := len(hs)
		if (n - res) % 2 == 1 {
			res--
		}
		fmt.Printf("%d\n", res)
	}
}