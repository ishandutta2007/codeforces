package main

import (
	"fmt"
	"sort"
)

func main() {
	var q int
	for fmt.Scan(&q); q > 0; q-- {
		var n int
		fmt.Scan(&n)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		sort.Ints(a)
		ans := 1
		for i := 0; i < n - 1; i++ {
			if a[i] == a[i + 1] - 1 {
				ans = 2
			}
		}
		fmt.Println(ans)
	}
}