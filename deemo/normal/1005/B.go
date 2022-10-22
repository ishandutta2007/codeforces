package main

import (
	"fmt"
)

func main() {
	var (
		s, t string
		ans int
	)

	fmt.Scan(&s)
	fmt.Scan(&t)
	ans = len(s) + len(t)

	/*for s != t {
		if len(s) > len(t) {
			s = s[1:]
		} else {
			t = t[1:]
		}
		ans++
	}*/

	for i := 0; i < len(s) && i < len(t) && t[len(t) - 1 - i] == s[len(s) - 1 - i]; i++ {
		ans -= 2;
	}

	fmt.Println(ans)
}