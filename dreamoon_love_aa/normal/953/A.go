package main

import "fmt"

func main() {
	var l int64
    var r int64
	fmt.Scan(&l)
	fmt.Scan(&r)
    var ans = 0
	for i := 0; i < 33; i++ {
        for j := 0; j < 33; j++ {
            var me int64
            me = 1
            for k :=0; k < i; k++ {
                me = me * 2
            }
            for k :=0; k < j; k++ {
                me = me * 3
                if me > r {
                    break
                }
            }
            if me >= l {
                if me <= r{
                    ans = ans + 1
                }
            }
        }
	}
    fmt.Printf("%d\n",ans)
}