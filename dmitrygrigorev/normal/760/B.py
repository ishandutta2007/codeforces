n, m, k = list(map(int, input().split()))
left = 0
right = 10000000000
while (right - left > 1):
    mid = (left + right) // 2
    counter = mid
    lh = k - 1
    if lh >= mid - 1:
        counter += (mid - 1) * mid // 2
        counter += lh - (mid - 1)
    else:
        last_hobbit = mid - lh - 1
        counter += (mid - 1) * mid // 2 - (last_hobbit) * (last_hobbit + 1) // 2
    rh = n - k
    if rh >= mid - 1:
        counter += (mid - 1) * mid // 2
        counter += rh - (mid - 1)
    else:
        last_hobbit = mid - rh - 1
        counter += (mid - 1) * mid // 2 - (last_hobbit) * (last_hobbit + 1) // 2    
    if counter > m:
        right = mid
    else:
        left = mid
print(left)