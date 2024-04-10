for testcase in range(int(input())):
    vals = list(map(int, input().split()))
    
    ans = None
    for a in vals:
        for b in vals:
            for c in vals:
                if max(a, b) == vals[0] and max(a, c) == vals[1] and max(b, c) == vals[2]:
                    ans = [a, b, c]
    
    if ans is None:
        print("NO")
    else:
        print("YES")
        print(*ans)