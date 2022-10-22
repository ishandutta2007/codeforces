package main

import "fmt"

func main()  {
	var n, cnt int;
	fmt.Scan(&n)
	var res []int
	for i, x := 0, 0; i < n; i++ {
		fmt.Scan(&x)
		if x == 1 {
			if cnt > 0 {
				res = append(res, cnt)
			}
			cnt = 0
		}
		cnt++
	}
	if cnt > 0 {
		res = append(res, cnt)
	}
	fmt.Println(len(res))
	for _, val := range res {
		fmt.Print(val, " ")
	}
	fmt.Println()
}