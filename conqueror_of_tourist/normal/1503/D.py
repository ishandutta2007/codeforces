import sys
input = sys.stdin.readline

n = int(input())

front = [-1] * n
back = [-1] * n
rev = [-1] * (2 * n)
used = [False] * n
opp = [-1] * (2 * n)

for c in range(n):
    a, b = map(lambda x: int(x) - 1, input().split())
    front[c] = a
    back[c] = b
    rev[a] = c
    rev[b] = c
    opp[a] = b
    opp[b] = a


left = -1
right = 2 * n
out = 0
works = True
while right - left > 1:
    s_l = left + 1
    s_r = right
    curr = 0
    curr_f = 0

    while (s_l > left or s_r < right) and right - left > 1:
        #print(left, s_l, s_r, right)
        if s_l > left:
            left += 1
            card = rev[left]
            if not used[card]:
                used[card] = True
                curr += 1
                if front[card] == left:
                    curr_f += 1
                if opp[left] < s_r:
                    s_r = opp[left]
                else:
                    works = False
        elif s_r < right:
            right -= 1
            card = rev[right]
            if not used[card]:
                used[card] = True
                curr += 1
                if front[card] == right:
                    curr_f += 1
                if opp[right] > s_l:
                    s_l = opp[right]
                else:
                    works = False
    if s_l > s_r:
        works = False
    if not works:
        break
    out += min(curr_f, curr - curr_f)

if works:
    print(out)
else:
    print(-1)