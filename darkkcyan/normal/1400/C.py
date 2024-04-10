for test in range(int(input())):
    s = input().strip()
    x = int(input())
    w = [' '] * len(s)
    for id, val in enumerate(s):
        if val == '1':
            continue
        if id - x >= 0:
            w[id - x] = '0'
        if id + x < len(s):
            w[id + x] = '0'
    for id, val in enumerate(s):
        if val == '0':
            continue
        if (id - x < 0 or w[id - x] == '0') and (id + x >= len(s) or w[id + x] == '0'):
            w = ['-', '1']
            break
        if id - x >= 0 and w[id - x] == ' ':
            w[id - x] = '1'
        if id + x < len(s) and w[id + x] == ' ':
            w[id + x] = '1'
    for i in range(len(w)):
        if w[i] == ' ':
            w[i] = '1'
    print(''.join(w))