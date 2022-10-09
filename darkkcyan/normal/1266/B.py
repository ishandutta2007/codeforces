from sys import stdin, exit
ntest = int(stdin.readline())
for test in map(int, stdin.readline().split()):
    ok = False
    for rem_face in range(1, 7):
        n = test
        n -= 21 - rem_face
        if n < 0 or n % 14 != 0:
            continue
        ok = True
        break
    print('YES' if ok else 'NO')