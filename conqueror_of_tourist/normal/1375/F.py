import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
p = [a,b,c]
print("First")
sys.stdout.flush()
print(a + b + c)
sys.stdout.flush()
action = a + b + c

done = False
while not done:
    res = int(input())
    if res < 1:
        done = True
    else:
        p[res - 1] += action

        smol = min(p)
        tol = max(p)
        mid = sum(p) - smol - tol

        if tol - mid == mid - smol:
            print(tol - mid)
            action = tol - mid
        else:
            print((mid - smol) + 2 * (tol - mid))
            action = (mid - smol) + 2 * (tol - mid)
        sys.stdout.flush()