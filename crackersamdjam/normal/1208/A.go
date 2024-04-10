package main
import (
	"fmt"
)
func main(){
	var t, a, b, n int
	fmt.Scanf("%d\n", &t);
	for tc := 0; tc < t; tc++ {
		fmt.Scanf("%d %d %d\n", &a, &b, &n);
		switch (n+1)%3 {
		case 0:
			fmt.Println(a^b)
		case 1:
			fmt.Println(a)
		case 2:
			fmt.Println(b)
		}
	}
}