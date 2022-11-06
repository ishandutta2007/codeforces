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
    s = input().strip()
    if s == 'a1' or s == 'a8' or s == 'h8' or s == 'h1':
        print(3)
    elif s[0:1] == 'a' or s[0:1] == 'h' or s[1:2] == '1' or s[1:2] == '8':
        print(5)
    else:
        print(8)

main()