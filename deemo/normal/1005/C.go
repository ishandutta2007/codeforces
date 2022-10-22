package main

import (
	"fmt"
	"sort"
)

func main() {
	var (
		n, ans int
		a []int
	)

	fmt.Scan(&n)
	ans = n;
	a = make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)

	for i, val := range a {
		var found bool
		for j := 0; !found && j < 31; j++ {
			p := 1 << uint(j)
			req := p - val
			if req < 0 {
				continue
			}

			ind := sort.Search(n, func(ind int) bool {
				return a[ind] > req
			})
			found = ind - 1 >= 0 && a[ind-1] == req && ind-1 != i

			ind = sort.Search(n, func(ind int) bool {
				return a[ind] >= req
			})
			found = found || (ind < n && a[ind] == req && ind != i)
		}

		if found {
			ans--
		}
	}

	fmt.Println(ans)
}