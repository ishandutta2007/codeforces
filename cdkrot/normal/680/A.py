#!/usr/bin/python3
# Copyright (C) 2016 Sayutin Dmitry.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; version 3
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; If not, see <http://www.gnu.org/licenses/>.

def main():
    t = list(map(int, input().split()))
    min_ans = t[0] + t[1] + t[2] + t[3] + t[4]
    sm = min_ans
    
    for i in range(5):
        for j in range(i + 1, 5):
            if t[i] == t[j]:
                min_ans = min(min_ans, sm - t[i] - t[j])
                for k in range(j + 1, 5):
                    if t[i] == t[j] == t[k]:
                        min_ans = min(min_ans, sm - 3 * t[i])
    print(min_ans)


main()