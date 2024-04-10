#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
def recursion(n, string, step, last, con):
    ss = ""
    minim = 10**18 + 1
    i = last
    while i > 0:
        ss = string[i] + ss
        if (len(ss) > 19):
            break
        nn = int(ss);
        if (nn >= n):
            break
        nn = nn * step
        if (nn > con):
            break
        if (string[i] != '0' or len(ss) == 1):
            minim = min(minim, nn + recursion(n, string, step * n, i - 1, con))
        i -= 1
    sss = ""
    for i in range(last + 1):
        sss += string[i]
    if (len(sss) > 19):
        return minim
    nnn = int(sss)
    sas = nnn * step
    if (nnn < n and sas >= 0 and sas <= con):
        minim = min(minim, nnn * step)
    
    return minim

con = 10 ** 18
n = int(input())
string = input()
answer = 0;
if (n <= 10):
    step = 1;
    for i in range(len(string)):
        ss = "";
        ss += string[len(string) - i - 1]
        answer += step * int(ss)
        step = step * n
    print(answer)
else:
    answer = recursion(n, string, 1, len(string) - 1, con)
    print(answer)