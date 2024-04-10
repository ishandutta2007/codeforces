package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

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

func solve() {
	var n int
	scan(&n)
	last, cnt := -1, 0
	ans := 1
	for i := 0; i < n; i++ {
		var x int
		scan(&x)
		if x == last {
			cnt += 1
		} else {
			last = x
			cnt = 1
		}
		if cnt > ans {
			ans = cnt
		}
	}
	printf("%d\n", ans)
	//writer.Flush()
}

func main() {
	defer writer.Flush()

	testCases := 0
	scan(&testCases)
	for i := 0; i < testCases; i++ {
		solve()
	}
}