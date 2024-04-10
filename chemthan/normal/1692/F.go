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
		var _ = readInt()
		var a = readArrInt()
		var cnt = [10]int{}
		for i := range a {
			cnt[a[i]%10]++
		}
		var found = false
		for i := range cnt {
			for j := range cnt {
				for k := range cnt {
					cnt[i]--
					cnt[j]--
					cnt[k]--
					if 0 <= cnt[i] && 0 <= cnt[j] && 0 <= cnt[k] && (i + j + k) % 10 == 3 {
						found = true
					}
					cnt[i]++
					cnt[j]++
					cnt[k]++
				}
			}
		}
		if found {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}