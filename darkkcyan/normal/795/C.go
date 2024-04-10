package main
import (
    "fmt"
)

func main() {
    var n int
    fmt.Scan(&n)
    cnt := 0
    hasleft := 0
    if n % 2 == 1 {
        cnt = (n - 3) / 2
        hasleft = 1
    } else {
        cnt = n / 2
    }
    if hasleft == 1 {
        fmt.Print(7)
    }
    for i := 0; i < cnt; i ++ {
        fmt.Print(1)
    }
}