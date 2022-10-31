package main

import "fmt"
func main() {
    p:=[...][8]int{{3,3,0,4,4,0,3,3},{3,3,0,4,4,0,3,3},{2,2,0,3,3,0,2,2},{2,2,0,3,3,0,2,2},{1,1,0,2,2,0,1,1},{1,1,0,2,2,0,1,1}}
    var s [6]string
    for i:=0;i<6;i++ {
        fmt.Scanln(&s[i])
    }
    flag :=false
    for i:=4;!flag&&i>=1;i-- {
        for j:=0;!flag&&j<6;j++ {
            for k:=0;!flag&&k<8;k++ {
                if p[j][k]==i&&s[j][k]=='.' {
                    s[j]=s[j][0:k]+"P"+s[j][k+1:8]
                    flag=true
                }
            }
        }
    }
    for i:=0;i<6;i++ {
        fmt.Printf("%s\n",s[i])
    }
}