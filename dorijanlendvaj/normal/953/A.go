package main 

import "fmt"

func main() {
	var l, r, c int64
	fmt.Scan(&l, &r)
	c = 0
	for i := 0; i < 32; i++ {
	    var x int64
	    x = 1
	    for j := 0; j < i; j++ {
	        x = x*2
	    }
	    for j := 0; j < 21; j++ {
	        if x > l - 1 {
	            if x < r + 1 {
	                c = c+1
	            }
	        }
	        x = x*3
	    }
	}
	fmt.Println(c)
}