package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

const MAXV = 90
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		log.Fatal(err)
	}
}

func scanf(f string, a ...interface{}) {
	if _, err := fmt.Fscanf(reader, f, a...); err != nil {
		log.Fatal(err)
	}
}

func printf(f string, a ...interface{}) {
	if _, err := fmt.Fprintf(writer, f, a...); err != nil {
		log.Fatal(err)
	}
}

func isLucky(v int, d int) bool {
	for v > 0 {
		if v % 10 == d {
			return true
		}
		v /= 10
	}
	return false
}

func solve() {
	var q, d int
	scan(&q, &d)
	var dp = make([]bool, MAXV)
	dp[0] = true
	for v := 0; v < MAXV; v++ {
		if dp[v] {
			continue
		}
		for vv := 1; vv <= v; vv++ {
			if isLucky(vv, d) && dp[v - vv] {
				dp[v] = true
				break
			}
		}
	}
	for i := 0; i < q; i++ {
		var x int
		scan(&x)
		if x >= 10 * d || dp[x] {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
	}
}

func main() {
	defer writer.Flush()

	testCases := 0
	scan(&testCases)
	for ; testCases > 0; {
		testCases -= 1
		solve()
	}
}