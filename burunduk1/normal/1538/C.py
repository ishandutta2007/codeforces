for cycle in range(int(input())):
    n,l,r = [int(x) for x in input().split()]
    a = sorted([int(x) for x in input().split()])
    var = 0
    n = len(a)
    min_j, max_j = n-1, n-1
    ans = 0
    # print(f"a={a}, l={l}, r={r}")
    # i < j
    for i in range(n-1):
        while max_j >= 0 and a[i] + a[max_j] > r: # <= r
            max_j -= 1
        while min_j >= 0 and a[i] + a[min_j] >= l:
            min_j -= 1
        # print(f"for a[i={i}]={a[i]} j in ({min_j},{max_j}]")
        # [min_j+1,max_j]   (min_j,max_j)
        ans += max(0, max_j - max(min_j, i))
    print(ans)



# ......i...............
# ...........[jjjj].....
# .......i..............
# ..........<-...<-.....