from __future__ import print_function, division
from sys import stdin, exit

def no_ans():
    print(":(")
    exit(0)

n = int(stdin.readline())
s = [ch for ch in stdin.readline()[:n]]

if n % 2 == 1 or s[0] == ')' or s[-1] == '(':
    no_ans()

s[0] = '('
s[-1] = ')'

cur_open = 0
open_left = (n - 1) // 2 - s[1:n - 1].count('(')

for i, char in enumerate(s[1:n - 1], 1):
    if char == '(':
        cur_open += 1
    elif char == '?' and open_left > 0:
        cur_open += 1
        open_left -= 1
        s[i] = '('
    else:
        cur_open -= 1
        s[i] = ')'
        if cur_open < 0:
            no_ans()
if cur_open != 0:
    no_ans()

print(''.join(s))