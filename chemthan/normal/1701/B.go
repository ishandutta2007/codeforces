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
		n := readInt()
		hs := make(map[int]int)
		fmt.Println("2")
		for i := 1; i <= n; i++ {
			t := i
			for hs[t] == 0 && t <= n {
				hs[t] = 1
				fmt.Printf("%d ", t)
				t *= 2
			}
		}
		fmt.Println()
	}
}